fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val x = readLine()!!.split(" ").map { it.toInt() }
        for(i in 0 until n-1)
            if((x[i] + x[i+1]) % 2 == 0){
                println("YES")
                return@repeat
            }
        println("NO")
    }
}