-- [programmersSQL]루시와 엘라 찾기

SELECT 
    AIN.ANIMAL_ID,
    AIN.NAME,
    AIN.SEX_UPON_INTAKE
FROM ANIMAL_INS AS AIN
WHERE AIN.NAME IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')
ORDER BY AIN.ANIMAL_ID;
