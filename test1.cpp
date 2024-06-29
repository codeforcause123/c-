#include <bits/stdc++.h>
using namespace std;

struct AttendanceResult
{
    int remainingClasses;
    double attendancePercentage;
    double requiredAttendance;
    int margin;
};

AttendanceResult calculateAttendanceMargin(int attendedClasses, int totalClasses)
{
    AttendanceResult result;
    result.remainingClasses = totalClasses - attendedClasses;
    result.attendancePercentage = (static_cast<double>(attendedClasses) / totalClasses) * 100;
    result.requiredAttendance = static_cast<double>(0.75 * totalClasses);
    result.margin = ceil(result.requiredAttendance - attendedClasses);

    return result;
}

int main()
{
    int attendedClasses, totalClasses;

    cout << "Enter the number of classes attended: ";
    cin >> attendedClasses;

    cout << "Enter the total number of classes: ";
    cin >> totalClasses;

    AttendanceResult result = calculateAttendanceMargin(attendedClasses, totalClasses);
    cout << result.attendancePercentage << endl;
    if (result.attendancePercentage > 75)
    {
        cout << "Margin: " << abs(result.margin) << " classes" << endl;
    }
    else
    {
        cout << "Required Classes: " << abs(result.margin) << " classes" << endl;
    }

    return 0;
}
