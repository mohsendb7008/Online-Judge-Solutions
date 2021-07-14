fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").mapIndexed { index, it -> it.toLong() to index }.sortedBy { it.first }
    val sum = a.sumOf { it.first }
    val ans = ArrayList<Int>()
    for(i in 0 until n) {
        val newSum = sum - a[i].first
        val maxItem = a[if(i == n-1) n-2 else n-1].first
        if(maxItem * 2 == newSum)
            ans.add(a[i].second + 1)
    }
    println(ans.size)
    println(ans.joinToString(separator = " "))
}