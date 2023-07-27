/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int DFS(vector<Employee*>& employees, int id)
    {
        auto employeeV = employees[um[id]]->subordinates;
        if (employeeV.size() == 0)
            return employees[um[id]]->importance;
        int ret = 0;
        //求他的下属的重要度
        for (int i = 0; i < employeeV.size(); i++)
        {
            ret += DFS(employees, employeeV[i]);
        }
        //加上自己的重要度
        return ret + employees[um[id]]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //建立一个数组下标和id的映射
        for (int i = 0; i < employees.size(); i++)
        {
            um[employees[i]->id] = i;
        }
        return DFS(employees, id);
    }
private:
    unordered_map<int, int> um;
};