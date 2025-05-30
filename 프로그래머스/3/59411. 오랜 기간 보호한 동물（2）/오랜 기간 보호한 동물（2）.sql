SELECT ai.ANIMAL_ID, ai.NAME
FROM ANIMAL_INS AS ai LEFT JOIN ANIMAL_OUTS AS ao ON ai.ANIMAL_ID = ao.ANIMAL_ID
ORDER BY DATEDIFF(ao.DATETIME, ai.DATETIME) DESC
LIMIT 2;