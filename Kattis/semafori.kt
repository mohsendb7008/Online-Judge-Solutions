// Semafori

fun List<Int>.toTriple() = Triple(this[0], this[1], this[2])

fun main() {
    val(N, L) = readLine()!!.split(" ").map { it.toInt() }
    val tls = Array(N) { readLine()!!.split(" ").map { it.toInt() }.toTriple() }
    var ans = 0
    for(i in 0 until N){
        ans += tls[i].first - (tls.getOrNull(i-1)?.first ?: 0)
        if(ans % (tls[i].second + tls[i].third) < tls[i].second)
            ans += tls[i].second - ans % (tls[i].second + tls[i].third)
    }
    ans += L - tls.last().first
    println(ans)
}