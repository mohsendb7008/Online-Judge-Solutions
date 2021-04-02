fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }.mapIndexed { index, i ->  index + 1 to i}.toMutableList()
        if(n == 1)
            println(1)
        else {
            a.sortBy { it.second }
            val b = IntArray(n){0}
            var iter = 0
            var i = 0
            while(i < n){
                iter += a[i].second
                if(iter >= n)
                    break
                b[iter] = a[i].first
                i++
            }
            for(j in 0 until n)
                if(b[j] == 0) {
                    b[j] = a[i].first
                    i++
                }
            println(b.joinToString(separator = " "))
        }
    }
}