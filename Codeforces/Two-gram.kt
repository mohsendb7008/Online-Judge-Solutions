val occur = HashMap<String, Int>()

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    for(i in 0 until n-1) {
        val t = s.substring(i, i+2)
        if(t in occur)
            occur[t] = occur[t]!! + 1
        else
            occur[t] = 1
    }
    println(occur.maxBy { it.value }!!.key)
}