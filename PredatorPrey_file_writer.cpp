/**
 * Code in this file is intended to output the results of Predator-Prey model into files which are then
 * passed to gnuplot in files PopulationsDrawer and K_of_v_drawer.
 */

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define ll long long int

using namespace std;

int main () {

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    ll victims, killers, number_of_points, T;
    cin >> victims >> killers;
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> T >> number_of_points;
    double timeStep = (double)T / (double)number_of_points;

    vector<double> victims_at_moments;
    vector<double> killers_at_moments;

    double victims0 = victims - a2/b2;
    double killers0 = killers - a1/b1;

    for (double t = 0; t <= T; t += timeStep) {
        double v_t = double(victims0) * cos(sqrt(a1 * a2) * t) - double(killers0) * (sqrt(a2) * b1/(b2 * sqrt(a1))
                                                                                     * sin(sqrt(a1 * a2) * t));
        double k_t = double(victims0) * (sqrt(a1) * b2 / (b1 * sqrt(a2))) * sin(sqrt(a1 * a2) * t) +
                     double(killers0) * cos(sqrt(a1 * a2) * t);

        double V_t = v_t + a2/b2;
        double K_t = k_t + a1/b1;

        victims_at_moments.pb(V_t);
        killers_at_moments.pb(K_t);
    }
    auto vic = fopen("victims.dat", "w");
    int i = 0;
    for (double t = 0; t<=T; t += timeStep) {
        fprintf(vic, "%f %f\n", t, victims_at_moments[i++]);
    }
    fclose(vic);
    auto kil = fopen("killers.dat", "w");
    i = 0;
    for (double t = 0; t<=T; t+= timeStep) {
        fprintf(kil, "%f %f\n", t, killers_at_moments[i++]);
    }
    auto k_v = fopen("killers_on_victims.dat", "w");
    for (int i = 0; i < killers_at_moments.size(); i++) {
        fprintf(k_v, "%f %f\n", victims_at_moments[i], killers_at_moments[i]);
    }

    return 0;
}
