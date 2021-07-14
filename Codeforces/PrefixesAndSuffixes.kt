val fixes = Array(100) { ArrayList<Pair<String, Int>>() }
val ans = CharArray(198)

fun evaluate(s: String): Boolean {
    for (i in 1 until s.length - 1) {
        if (s.startsWith(fixes[i][0].first) && s.endsWith(fixes[i][1].first)) {
            ans[fixes[i][0].second] = 'P'
            ans[fixes[i][1].second] = 'S'
        } else if (s.startsWith(fixes[i][1].first) && s.endsWith(fixes[i][0].first)) {
            ans[fixes[i][1].second] = 'P'
            ans[fixes[i][0].second] = 'S'
        }
        else
            return false
    }
    return true
}

fun main() {
    val n = readLine()!!.toInt()
    repeat(2 * n - 2) {
        val str = readLine()!!
        fixes[str.length].add(str to it)
    }
    if (n == 2) {
        println("PS")
        return
    }
    if(fixes[n-1][0].first.drop(1) == fixes[n-1][1].first.dropLast(1) && evaluate(fixes[n-1][0].first.take(1) + fixes[n-1][1].first)) {
        ans[fixes[n-1][0].second] = 'P'
        ans[fixes[n-1][1].second] = 'S'
    }
    else {
        evaluate(fixes[n-1][1].first + fixes[n-1][0].first.takeLast(1))
        ans[fixes[n-1][1].second] = 'P'
        ans[fixes[n-1][0].second] = 'S'
    }
    println(ans.take(2 * n - 2).joinToString(separator = ""))
}