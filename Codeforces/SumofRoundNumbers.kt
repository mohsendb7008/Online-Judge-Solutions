fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        var n = readLine()!!.toInt()
        val ans = ArrayList<Pair<Int, Int>>()
        var c = 0
        while(n != 0){
            if(n % 10 != 0)
                ans.add(n %10 to c)
            n /= 10
            c++
        }
        println(ans.size)
        ans.forEach {
            print(it.first)
            print("0".repeat(it.second))
            print(" ")
        }
        println()
    }
}