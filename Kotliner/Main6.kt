import java.util.PriorityQueue

fun main() {
    readln().toInt()
    val weights = readln().split(" ").map { it.toInt() }
    val pq = PriorityQueue<Long>()
    weights.forEach { weight -> pq.add(weight.toLong()) }
    var ans = 0L
    while (pq.size > 1) {
        val first = pq.poll()
        val second = pq.poll()
        val merged = first + second
        ans += merged
        pq.add(merged)
    }
    println(ans)
}