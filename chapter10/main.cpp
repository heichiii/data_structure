#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        total_score/=3;
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

// 创建学生对象
vector<Student> students = {
    Student(1, "Alice", "B1", {80, 90, 85}),
    Student(2, "Bob", "B1", {70, 85, 75}),
    Student(3, "Charlie", "B1", {90, 95, 92}),
    Student(4, "David", "B2", {60, 70, 65}),
    Student(5, "Eve", "B2", {80, 75, 70}),
    Student(6, "Frank", "B2", {90, 90, 90}),
    Student(7, "Grace", "B3", {70, 75, 80}),
    Student(8, "Heidi", "B3", {80, 85, 90}),
    Student(9, "Ivy", "B3", {90, 95, 100}),
    Student(10, "Julia", "B4", {60, 65, 70}),
    Student(11, "Kevin", "B4", {80, 85, 90}),
    Student(12, "Lily", "B4", {90, 95, 100}),
    Student(13, "Mary", "B5", {60, 65, 70}),
    Student(14, "Nancy", "B5", {80, 85, 90}),
    Student(15, "Olivia", "B5", {90, 95, 100}),
    Student(16, "Peter", "B6", {60, 65, 70}),
    Student(17, "Queen", "B6", {80, 85, 90}),
    Student(18, "Rose", "B6", {90, 95, 100}),
    Student(19, "Sarah", "B7", {60, 65, 70}),
    Student(20, "Tom", "B7", {80, 85, 90}),
    Student(21, "Ursula", "B7", {90, 95, 100}),
    Student(22, "Victor", "B8", {60, 65, 70}),
    Student(23, "Wendy", "B8", {80, 85, 90}),
    Student(24, "Xavier", "B8", {90, 95, 100}),
    Student(25, "Yvonne", "B9", {60, 65, 70}),
    Student(26, "Zoe", "B9", {80, 85, 90}),
    Student(27, "Amy", "B9", {90, 95, 100}),
    Student(28, "Ben", "B10", {60, 65, 70}),
    Student(29, "Cindy", "B10", {80, 85, 90}),
    Student(30, "David2", "B10", {90, 95, 100}),

};

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
    Class("B10", {students[27], students[28], students[29]}),

};

// 显示学生考试情况
void displayAllStudents()
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.total_score > b.total_score; });
    cout<<"---------------------all students------------------------"<<endl;
    for (const Student &student : students)
    {
        cout << "Student ID: " << student.student_id
             << ", Name: " << student.name
             << ", Total Score: " << student.total_score << endl;
    }
    cout<<"---------------------all students------------------------"<<endl;
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
    cout<<"---------------------"+class_id;
    cout<<"-students------------------------"<<endl;
    for (const Student &student : class_students)
    {
        cout << "Student ID: " << student.student_id
             << ", Name: " << student.name
             << ", Total Score: " << student.total_score << endl;
    }
    cout<<"---------------------"+class_id;
    cout<<"-students------------------------"<<endl;
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
void statisticsCourseScores()
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
//    displayAllStudents();
//    cout << endl;

//     displayClassStudents("B1");
//     displayClassStudents("B2");
//     displayClassStudents("B3");
//     displayClassStudents("B4");
//     displayClassStudents("B5");
//     displayClassStudents("B6");
//     displayClassStudents("B7");
//     displayClassStudents("B8");
//     displayClassStudents("B9");
//     displayClassStudents("B10");
//     cout << endl;

//     displayStudentScores(2);
//     cout << endl;

     statisticsTotalScores();

    return 0;
}