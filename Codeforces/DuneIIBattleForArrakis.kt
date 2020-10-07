import kotlin.math.min

val g = Array(1003){IntArray(1003)}

fun solve(a: LongArray): Long{
    val(lpsum, lpsum2, rpsum, rpsum2) = listOf(LongArray(a.size), LongArray(a.size), LongArray(a.size), LongArray(a.size))
    lpsum[0] = a[0]
    for(i in 1 until a.size)
        lpsum[i] = lpsum[i-1] + a[i]
    lpsum2[0] = lpsum[0]
    for(i in 1 until a.size)
        lpsum2[i] = lpsum2[i-1] + lpsum[i]
    rpsum[a.size-1] = a[a.size-1]
    for(i in a.size - 2 downTo 0)
        rpsum[i] = rpsum[i+1] + a[i]
    rpsum2[a.size-1] = rpsum[a.size-1]
    for(i in a.size - 2 downTo 0)
        rpsum2[i] = rpsum2[i+1] + rpsum[i]
    var ans = Long.MAX_VALUE
    for(i in a.indices){
        var curr = 0L
        if(i > 0)
            curr += lpsum2[i-1]
        if(i < a.size - 1)
            curr += rpsum2[i+1]
        ans = min(ans, curr)
    }
    return ans
}

fun main() {
    val(n, m, q) = readLine()!!.split(" ").map { it.toInt() }
    for(i in 0 until n)
        g[i] = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val rows = LongArray(n)
    val cols = LongArray(m)
    for(i in 0 until n)
        for(j in 0 until m){
            rows[i] += g[i][j].toLong()
            cols[j] += g[i][j].toLong()
        }
    print("${solve(rows) + solve(cols)} ")
    repeat(q){
        val(x, y, z) = readLine()!!.split(" ").map { it.toInt() }
        val diff = z - g[x-1][y-1]
        g[x-1][y-1] = z
        rows[x-1] += diff.toLong()
        cols[y-1] += diff.toLong()
        print("${solve(rows) + solve(cols)} ")
    }
}