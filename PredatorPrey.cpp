/**
 * Code in this file passes all the tests on Yandex platform contest, provided by AGLA II team.
 * There is PredatorPrey_file_writer.cpp file that does the same computations, but outputs data into
 * files, which is then plotted in gnuplot.
 */

#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define ll long long int

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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

    cout << "t:\n";

    double victims0 = victims - a2/b2;
    double killers0 = killers - a1/b1;

    for (double t = 0; t <= T; t += timeStep) {
        cout << t << " ";
        double v_t = double(victims0) * cos(sqrt(a1 * a2) * t) - double(killers0) * (sqrt(a2) * b1/(b2 * sqrt(a1))
                                                                                     * sin(sqrt(a1 * a2) * t));
        double k_t = double(victims0) * (sqrt(a1) * b2 / (b1 * sqrt(a2))) * sin(sqrt(a1 * a2) * t) +
                     double(killers0) * cos(sqrt(a1 * a2) * t);

        double V_t = v_t + a2/b2;
        double K_t = k_t + a1/b1;

        victims_at_moments.pb(V_t);
        killers_at_moments.pb(K_t);
    }

    cout << "\nv:\n";
    for (auto& v: victims_at_moments)
        cout << v << " ";
    cout << "\n";

    cout << "k:\n";
    for (auto& k: killers_at_moments)
        cout << k << " ";

    return 0;
}

