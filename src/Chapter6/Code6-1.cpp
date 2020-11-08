// Code 6-1

#include <iostream>
using namespace std;
#define NAME_MAX_LEN 16 //姓名最大长度
#define AGE_MIN 1       //年龄最小值
#define AGE_MAX 150     //年龄最大值
#define WEIGHT_MIN 10   //体重最小值
#define WEIGHT_MAX 500  //体重最大值
#define LUGGAGE_MIN 1   //行李重量最小值
#define LUGGAGE_MAX 500 //行李重量最大值

struct Passenger
{
    unsigned int no;    //号码
    char name[16];      //姓名
    unsigned int age;   //年龄
    char sex;           //性别
    float weight;       //体重
    float luggage;      //行李重量
    char meal;          //膳食种类
    float weight_total; //总重量
};//声明乘客信息结构体类型

int main()
{
    unsigned int age = 0;           //年龄
    char sex = 0;                   //性别
    float weight = 0;               //体重
    float luggage = 0;              //行李重量
    char meal = 0;                  //膳食种类
    char command = 0;               //输入命令
    unsigned int num = 0;           //乘客数量
    struct Passenger message[1024]; //定义乘客信息结构体
    while (1)
    {
        cout << "请输入命令:\r\n""i:输入乘客信息;\r\na:按照年龄顺序排序;\r\nn:按照编号顺序排序;\r\nw:按照体重顺序排序;\r\ns:输出乘客信息;"
            << "\r\nx:输出男女数量;"
            << "\r\nl:输出小于18岁乘客信息;"
            << "\r\nA:输出A套餐乘客信息;"
            << "\r\nB:输出B套餐乘客信息;" << endl;
        cin >> command;
        switch (command)
        {
        case 'i': //信息输入
        {
            while (1)
            {
                cout << "键入任意键继续输入，结束输入请键入 q" << endl;
                cin >> command;
                if (command == 'q')
                {
                    cout << "输入结束" << endl;
                    break;
                }
                //输入编号
                cout << "请输入乘客编号，以回车结束" << endl;
                cin >> message[num].no;
                //输入姓名
                cout << "请输入乘客姓名，以回车结束" << endl;
                cin >> message[num].name;
                //输入年龄
                while (1)
                {
                    cout << "请输入乘客年龄，以回车结束" << endl;
                    cin >> age;
                    if (age < AGE_MIN || age > AGE_MAX)
                    {
                        cout << "年龄范围错误请重新输入" << endl;
                    }
                    else
                    {
                        message[num].age = age;
                        break;
                    }
                }
                //输入性别
                while (1)
                {
                    cout << "请输入乘客性别，以回车结束" << endl;
                    cin >> sex;
                    if (sex != 'M' && sex != 'F')
                    {
                        cout << "性别输入错误请重新输入" << endl;
                    }
                    else
                    {
                        message[num].sex = sex;
                        break;
                    }
                }
                //输入体重
                while (1)
                {
                    cout << "请输入乘客体重，以回车结束" << endl;
                    cin >> weight;
                    if (weight < WEIGHT_MIN || weight > WEIGHT_MAX)
                    {
                        cout << "体重范围错误请重新输入" << endl;
                    }
                    else
                    {
                        message[num].weight = weight;
                        break;
                    }
                }
                //输入行李重量
                while (1)
                {
                    cout << "请输入乘客行李重量，以回车结束" << endl;
                    cin >> luggage;
                    if (luggage < LUGGAGE_MIN || luggage > LUGGAGE_MAX)
                    {
                        cout << "行李重量范围错误请重新输入" << endl;
                    }
                    else
                    {
                        message[num].luggage = luggage;
                        break;
                    }
                }
                //输入膳食类型
                while (1)
                {
                    cout << "请输入乘客膳食类型，以回车结束" << endl;
                    cin >> meal;
                    if (meal != 'A' && meal != 'B')
                    {
                        cout << "膳食类型错误请重新输入" << endl;
                    }
                    else
                    {
                        message[num].meal = meal;
                        break;
                    }
                }
                message[num].weight_total = message[num].weight + message[num].luggage; //统计行李和体重总重量
                num++;                                                                  //累计乘客个数
            }
        }
        break;
        case 'a': //按年龄排序
        case 'w': //按重量排序
        case 'n': //按序号排序
        {
            struct Passenger cmp_data_temp;
            for (unsigned int i = 0; i < num - 1; ++i) //冒泡排序
            {
                for (unsigned int j = 0; j < num - 1 - i; ++j)
                {
                    if (command == 'a')
                    {
                        if (message[j].age <= message[j + 1].age)
                        {
                            continue;
                        }
                    }
                    if (command == 'w')
                    {
                        if (message[j].weight_total <= message[j + 1].weight_total)
                        {
                            continue;
                        }
                    }
                    if (command == 'n')
                    {
                        if (message[j].no <= message[j + 1].no)
                        {
                            continue;
                        }
                    }
                    cmp_data_temp = message[j];
                    message[j] = message[j + 1];
                    message[j + 1] = cmp_data_temp;
                }
            }
        }
        case 's': //显示乘客信息
        {
            cout << "NO    Name            Age Sex Weight Luggage Meal" << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                cout.width(6);
                cout << left << message[i].no;
                cout.width(16);
                cout << message[i].name;
                cout.width(4);
                cout << message[i].age;
                cout.width(4);
                cout << message[i].sex;
                cout.width(7);
                cout << message[i].weight;
                cout.width(8);
                cout << message[i].luggage;
                cout.width(4);
                cout << message[i].meal << endl;
            }
        }
        break;
        case 'x': //显示男女数量
        {
            unsigned int male = 0;
            for (unsigned int i = 0; i < num; i++)
            {
                if (message[i].sex == 'M')
                {
                    male++;
                }
            }
            cout << "男士数量：" << male << endl
                << "女士数量：" << num - male << endl;
        }
        break;
        case 'l': //显示小于18岁乘客信息
        {
            cout << "NO    Name            Age Sex Weight Luggage Meal" << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                if (message[i].age >= 18)
                {
                    continue;
                }
                cout.width(6);
                cout << left << message[i].no;
                cout.width(16);
                cout << message[i].name;
                cout.width(4);
                cout << message[i].age;
                cout.width(4);
                cout << message[i].sex;
                cout.width(7);
                cout << message[i].weight;
                cout.width(8);
                cout << message[i].luggage;
                cout.width(4);
                cout << message[i].meal << endl;
            }
        }
        break;
        case 'A': //显示A套餐乘客信息
        {
            cout << "NO    Name            Age Sex Weight Luggage Meal" << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                if (message[i].meal != 'A')
                {
                    continue;
                }
                cout.width(6);
                cout << left << message[i].no;
                cout.width(16);
                cout << message[i].name;
                cout.width(4);
                cout << message[i].age;
                cout.width(4);
                cout << message[i].sex;
                cout.width(7);
                cout << message[i].weight;
                cout.width(8);
                cout << message[i].luggage;
                cout.width(4);
                cout << message[i].meal << endl;
            }
        }
        break;
        case 'B': //显示B套餐乘客信息
        {
            cout << "NO    Name            Age Sex Weight Luggage Meal" << endl;
            for (unsigned int i = 0; i < num; i++)
            {
                if (message[i].meal != 'B')
                {
                    continue;
                }
                cout.width(6);
                cout << left << message[i].no;
                cout.width(16);
                cout << message[i].name;
                cout.width(4);
                cout << message[i].age;
                cout.width(4);
                cout << message[i].sex;
                cout.width(7);
                cout << message[i].weight;
                cout.width(8);
                cout << message[i].luggage;
                cout.width(4);
                cout << message[i].meal << endl;
            }
        }
        break;
        default: //指令无法识别
        {
            cout << "错误指令" << endl;
        }
        break;
        }
    }
    return 0;
}