# Write your MySQL query statement below

SELECT wt.id
FROM Weather w
JOIN Weather wt
ON DATEDIFF(wt.recordDate, w.recordDate)=1
WHERE wt.temperature > w.temperature;