#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

// 定义学生类
class Student
{
public:
    int student_id;
    string name;
    string class_id;
    vector<int> scores;
    int total_score;

    Student(int id, string n, string cls, const vector<int> &scr)
    {
        student_id = id;
        name = n;
        class_id = cls;
        scores = scr;
        total_score = 0;
        for (int score : scores)
        {
            total_score += score;
        }
    }
};

class Exam
{
public:
    string name;
    int time;
    Exam(const string& n,int t)
    {
        name==n;
        time=t;
    }
};
// 定义班级类
class Class
{
public:
    string class_id;
    vector<Student> students;

    Class(string cls, const vector<Student> &stds)
    {
        class_id = cls;
        students = stds;
    }
};

vector<Exam> es=
        {
                Exam("e1",60),
                Exam("e2",90),
};
vector<Student> students = {
    Student(1, "Alice", "B1", {80, 90, 85}),
    Student(2, "Bob", "B1", {7, 85, 75}),
    Student(3, "Charlie", "B1", {80, 95, 92}),
    Student(4, "Alice2", "B2", {81, 10, 85}),
    Student(5, "Bob2", "B2", {70, 15, 75}),
    Student(6, "Charlie2", "B2", {91, 95, 92}),
    Student(7, "Alice3", "B3", {82, 0, 85}),
    Student(8, "Bob3", "B3", {20, 51, 75}),
    Student(9, "Charlie3", "B3", {98, 95, 92}),
    Student(10, "Alice4", "B4", {80, 19, 85}),
    Student(11, "Bob4", "B4", {70, 5, 75}),
    Student(12, "Charlie4", "B4", {90, 25, 92}),
    Student(13, "Alice5", "B5", {10, 40, 25}),
    Student(14, "Bob5", "B5", {70, 35, 75}),
    Student(15, "Charlie5", "B5", {90, 99, 92}),
    Student(16, "Alice6", "6", {80, 0, 85}),
    Student(17, "Bob6", "B6", {30, 85, 75}),
    Student(18, "Charlie6", "B6", {40, 96, 92}),
    Student(19, "Alice7", "B7", {80, 90, 85}),
    Student(20, "Bob7", "B7", {74, 81, 68}),
    Student(21, "Charlie7", "B7", {90, 51, 92}),
    Student(22, "Alice8", "B8", {80, 90, 5}),
    Student(23, "Bob8", "B8", {70, 85, 75}),
    Student(24, "Charlie8", "B8", {90, 9, 92}),
    Student(25, "Alice9", "B9", {80, 92, 85}),
    Student(26, "Bob9", "B9", {70, 85, 75}),
    Student(27, "Charlie9", "B9", {90, 95, 92}),
    Student(28, "Alice10", "B10", {83, 91, 85}),
    Student(29, "Bob10", "B10", {78, 85, 75}),
    Student(30, "Charlie10", "B210", {0, 95, 92})};

// 创建班级对象
vector<Class> classes = {
    Class("B1", {students[0], students[1], students[2]}),
    Class("B2", {students[3], students[4], students[5]}),
    Class("B3", {students[6], students[7], students[8]}),
    Class("B4", {students[9], students[10], students[11]}),
    Class("B5", {students[12], students[13], students[14]}),
    Class("B6", {students[15], students[16], students[17]}),
    Class("B7", {students[18], students[19], students[20]}),
    Class("B8", {students[21], students[22], students[23]}),
    Class("B9", {students[24], students[25], students[26]}),
    Class("B10", {students[27], students[28], students[29]})};

// 显示学生考试情况
void displayAllStudents()
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.total_score > b.total_score; });

    for (const Student &student : students)
    {
        cout << "Student ID: " << student.student_id
             << ", Name: " << student.name
             << ", Total Score: " << student.total_score << endl;
    }
}

void displayClassStudents(string class_id)
{
    vector<Student> class_students;
    for (const Class &cls : classes)
    {
        if (cls.class_id == class_id)
        {
            class_students = cls.students;
            break;
        }
    }

    sort(class_students.begin(), class_students.end(), [](const Student &a, const Student &b)
         { return a.total_score > b.total_score; });

    for (const Student &student : class_students)
    {
        cout << "Student ID: " << student.student_id
             << ", Name: " << student.name
             << ", Total Score: " << student.total_score << endl;
    }
}

void displayStudentScores(int student_id)
{
    auto it = find_if(students.begin(), students.end(), [student_id](const Student &student)
                      { return student.student_id == student_id; });

    if (it != students.end())
    {
        const Student &student = *it;
        cout << "Student ID: " << student.student_id
             << ", Name: " << student.name
             << ", Scores: ";
        for (int score : student.scores)
        {
            cout << score << " ";
        }
        cout << ", Total Score: " << student.total_score << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}

// 统计学生考试成绩
void statisticsTotalScores()
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.total_score > b.total_score; });

    map<string, vector<Student>> score_ranges;
    score_ranges["90 and above"] = {};
    score_ranges["80 - 89"] = {};
    score_ranges["70 - 79"] = {};
    score_ranges["60 - 69"] = {};
    score_ranges["below 60"] = {};

    for (const Student &student : students)
    {
        if (student.total_score >= 90)
        {
            score_ranges["90 and above"].push_back(student);
        }
        else if (student.total_score >= 80)
        {
            score_ranges["80 - 89"].push_back(student);
        }
        else if (student.total_score >= 70)
        {
            score_ranges["70 - 79"].push_back(student);
        }
        else if (student.total_score >= 60)
        {
            score_ranges["60 - 69"].push_back(student);
        }
        else
        {
            score_ranges["below 60"].push_back(student);
        }
    }

    for (const auto &entry : score_ranges)
    {
        cout << "Score Range: " << entry.first << endl;
        for (const Student &student : entry.second)
        {
            cout << "Student ID: " << student.student_id
                 << ", Name: " << student.name
                 << ", Total Score: " << student.total_score << endl;
        }
        cout << endl;
    }
}

int main()
{
    displayAllStudents();
    cout << endl;

    displayClassStudents("B1");
    cout << endl;

    displayStudentScores(2);
    cout << endl;

    statisticsTotalScores();

    return 0;
}