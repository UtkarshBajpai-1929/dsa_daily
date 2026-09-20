# Write your MySQL query statement below
SELECT m.name
FROM Employee e
JOIN Employee m 
ON m.id = e.managerId
GROUP BY e.managerId
HAVING COUNT(*) >= 5