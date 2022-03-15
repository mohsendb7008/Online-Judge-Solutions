-- Section1
   SELECT id AS order_id FROM orders WHERE status = 'warehouse' ORDER BY order_id DESC;
-- Section2
   SELECT id AS customer_id, name AS customer_name FROM customers WHERE (SELECT COUNT(id) FROM orders WHERE customer_id = customers.id) = 0 ORDER BY customer_name;
-- Section3
SELECT not_blocked_orders_cnt.created_at AS date, IFNULL(format(main.total / not_blocked_orders_cnt.total * 100, 2), 0.00) AS cancellation_rate
FROM (SELECT COUNT(id) as total, not_blocked_orders.created_at
      FROM (SELECT *
            FROM orders
            WHERE (SELECT count(id) FROM customers WHERE id = customer_id AND (is_blocked = 0 OR is_blocked IS NULL)) >
                  0) AS not_blocked_orders
      WHERE status = 'canceled'
      GROUP BY created_at) AS main
         right join
     (SELECT created_at, COUNT(id) as total
      FROM (SELECT *
            FROM orders
            WHERE (SELECT count(id) FROM customers WHERE id = customer_id AND (is_blocked = 0 OR is_blocked IS NULL)) >
                  0) AS not_blocked_orders
      group by created_at) AS not_blocked_orders_cnt on main.created_at = not_blocked_orders_cnt.created_at;
