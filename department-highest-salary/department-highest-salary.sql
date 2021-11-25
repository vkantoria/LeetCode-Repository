SELECT Department.Name AS Department, Employee.Name AS Employee, Employee.Salary AS Salary
FROM Employee INNER JOIN Department
ON Employee.DepartmentId =Department.Id
WHERE Employee.Salary=
    (
        SELECT MAX(Salary) FROM Employee  
        WHERE Employee.DepartmentId=Department.Id
    );