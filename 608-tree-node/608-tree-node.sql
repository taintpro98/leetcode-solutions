# Write your MySQL query statement below
SELECT
    id AS `Id`,
    CASE
        WHEN p_id is null 
          THEN 'Root'
        WHEN id IN (SELECT p_id FROM tree)
          THEN 'Inner'
        ELSE 'Leaf'
    END AS Type
FROM
    tree
ORDER BY `Id`