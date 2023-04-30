#include <assert.h>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    FILE *plotHandle = nullptr;

    if(plotHandle == nullptr){
        plotHandle = popen("gnuplot-qt -persist", "w");
        assert(plotHandle != nullptr);
    }

    fprintf(plotHandle, "set xlabel \"Time\"\n");
    fprintf(plotHandle, "set ylabel \"Population\"\n");
    fprintf(plotHandle, "set title \"Victims and Killers populations with respect to time. "
                        "Conditions: v0, k0 = 6, a1 =.2, b1 =.025, a2 =.1, b2 =.02\"\n");
    fprintf(plotHandle, "plot \"/home/max/CLionProjects/TCS/cmake-build-debug/killers.dat\""
                        " with l lc rgb \"red\", ");
    fprintf(plotHandle, " \"/home/max/CLionProjects/TCS/cmake-build-debug/victims.dat\" with l\n");

    /**
     * Closing pipe, flushing out.
     */
    fflush(plotHandle);
    pclose(plotHandle);

    return 0;
}
