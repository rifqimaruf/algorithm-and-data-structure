# Customer Who Never Order

## Problem Example
Example 1:  

Input:   
Customers table:  
+----+-------+   
| id | name  |   
+----+-------+   
| 1  | Joe   |   
| 2  | Henry |   
| 3  | Sam   |   
| 4  | Max   |   
+----+-------+   
Orders table:  
+----+------------+  
| id | customerId |  
+----+------------+  
| 1  | 3          |  
| 2  | 1          |  
+----+------------+  
Output:   
+-----------+  
| Customers |  
+-----------+  
| Henry     |  
| Max       |  
+-----------+  

## Approach
We simply can use `Left join` on the table Customer and check the atribute orderId. Additionally to make the result set created as well as the output wanted, we can utilize use `AS`
