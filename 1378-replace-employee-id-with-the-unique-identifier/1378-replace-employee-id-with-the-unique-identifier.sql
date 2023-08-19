# Write your MySQL query statement below
SELECT name, unique_id
FROM Employees name
LEFT JOIN EmployeeUNI unique_id ON name.id = unique_id.id;
