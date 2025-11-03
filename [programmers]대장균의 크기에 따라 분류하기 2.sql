-- [programmers] 대장균의 크기에 따라 분류하기 2
WITH CNT AS (
    SELECT 
        e.ID,
        e.SIZE_OF_COLONY,
        (
            SELECT COUNT(*) + 1
            FROM ECOLI_DATA e1
            WHERE e1.SIZE_OF_COLONY > e.SIZE_OF_COLONY
        ) AS RN,
        (
            SELECT COUNT(*)
            FROM ECOLI_DATA 
        ) AS TOTAL
    FROM ECOLI_DATA e
)
SELECT 
    ID,
    CASE 
        WHEN RN <=TOTAL *0.25 THEN 'CRITICAL'
        WHEN RN <=TOTAL *0.5 THEN 'HIGH'
        WHEN RN <=TOTAL *0.75 THEN 'MEDIUM'
        ELSE 'LOW'
    END AS COLONY_NAME
FROM CNT
ORDER BY ID;