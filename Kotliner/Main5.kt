fun main() {
    val n = readln().toInt()
    val first = readln().split(" ").map { it.toInt() }.withIndex().sortedBy { it.value }.toList()
    val second = readln().split(" ").map { it.toInt() }.sorted().toList()
    var ans = 0L
    val order = IntArray(n)
    for (i in 0..<n) {
        ans += first[i].value.toLong() * second[i].toLong()
        order[first[i].index] = second[i]
    }
    println(ans)
    println(order.joinToString(" "))
}