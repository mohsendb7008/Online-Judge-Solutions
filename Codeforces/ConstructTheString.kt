fun main() {
    val alp = "abcdefghijklmnopqrstuvwxyz"
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, a, b) = readLine()!!.split(" ").map { it.toInt() }
        val cand = alp.substring(0, b) + "a".repeat(a - b)
        for(i in 0 until n)
            print(cand[i % a])
        println()
    }
}