// Video Speedup

fun main() {
    val(n, p, k) = readLine()!!.split(" ").map { it.toInt() }
    val t = readLine()!!.split(" ").map { it.toInt() }
    var (multiplier, ans) = 1.0 to 0.0
    for(i in 0 until n) {
        ans += (t[i] - t.getOrElse(i - 1) { 0 }) * multiplier
        multiplier += p.toDouble() / 100
    }
    ans += (k - t.last()) * multiplier
    println(ans)
}