fun main() {
    val mod = 1000000007L
    val x = readln().split(" ")[1].toLong()
    val ai = readln().split(" ").map { it.toLong() }.reversed()
    var ans = 0L
    var xi = 1L
    ai.forEach { a ->
        ans = (ans + (a * xi + mod) % mod + mod) % mod
        xi = (xi * x + mod) % mod
    }
    println(ans)
}