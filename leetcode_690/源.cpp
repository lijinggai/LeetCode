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
        //��������������Ҫ��
        for (int i = 0; i < employeeV.size(); i++)
        {
            ret += DFS(employees, employeeV[i]);
        }
        //�����Լ�����Ҫ��
        return ret + employees[um[id]]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //����һ�������±��id��ӳ��
        for (int i = 0; i < employees.size(); i++)
        {
            um[employees[i]->id] = i;
        }
        return DFS(employees, id);
    }
private:
    unordered_map<int, int> um;
};