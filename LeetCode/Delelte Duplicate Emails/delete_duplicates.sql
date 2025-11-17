
DELETE FROM Person
WHERE id NOT IN (
    SELECT MIN(id)
    FROM Person
    GROUP BY email
);
-- solved using subquery, by making a group of emails and keeping the one with the smallest id, support sqlite

-- DELETE p1
-- FROM Person p1
-- JOIN Person p2
--   ON p1.email = p2.email AND p1.id > p2.id;

-- alternate solution, self join and keeping the one with the smallest id, not supported in sqlite