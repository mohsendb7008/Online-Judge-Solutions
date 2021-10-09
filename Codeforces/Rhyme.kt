fun longestSuffix(s: String, t: String): Int {
    var(ans, sPtr, tPtr) = listOf(0, s.length - 1, t.length - 1)
    while (sPtr >= 0 && tPtr >= 0) {
        if (s[sPtr] != t[tPtr])
            break
        ans++
        sPtr--
        tPtr--
    }
    return ans
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val a = Array(n) { readLine()!!.split(" ").toList() }
        var(start, end) = Int.MIN_VALUE to Int.MAX_VALUE
        a.forEach {
            val ls = longestSuffix(it[0], it[1])
            if (it[2] == "1") {
                start = maxOf(start, 0)
                end = minOf(end, ls)
            }
            else {
                start = maxOf(start, ls + 1)
                end = minOf(end, Int.MAX_VALUE)
            }
        }
        if(start <= end) {
            println(end - start + 1)
            println((start..end).joinToString(separator = " "))
        }
        else {
            println(0)
        }
    }
}
