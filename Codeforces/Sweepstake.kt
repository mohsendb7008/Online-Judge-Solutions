fun main() {
    val(n, m) = readLine()!!.split(" ").map { it.toInt() }
    val survey = Array(m) { readLine()!!.split(" ").map { it.toInt() } }
    var ans = 1
    ans = maxOf(ans, (survey.filter { it[0] == survey[0][0] && it[1] != survey[0][1] }.groupingBy { it[1] }.eachCount().maxOfOrNull { it.value } ?: 0) + 1)
    ans = maxOf(ans, (survey.filter { it[1] == survey[0][1] && it[0] != survey[0][0] }.groupingBy { it[0] }.eachCount().maxOfOrNull { it.value } ?: 0) + 1)
    val a = HashMap<Int, Int>()
    val b = HashMap<Int, Int>()
    val ab = HashMap<Pair<Int, Int>, Int>()
    survey.forEach {
        a[it[0]] = a.getOrDefault(it[0], 0) + 1
        b[it[1]] = b.getOrDefault(it[1], 0) + 1
        ab[it[0] to it[1]] = ab.getOrDefault(it[0] to it[1], 0) + 1
    }
    for(i in 0 until n)
        for(j in 0 until n)
            if(i != j && survey[0][0] != i && survey[0][1] != j) {
                ans = maxOf(ans, a.getOrDefault(i, 0) + b.getOrDefault(j, 0) - ab.getOrDefault(i to j, 0) + 1)
            }
    println(ans)
}