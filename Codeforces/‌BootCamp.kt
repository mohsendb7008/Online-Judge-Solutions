fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val(n, k1, k2) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        var prevy = 0
        var m = 0
        for(i in 0 until n){
            if(s[i] == '0'){
                prevy = 0
                continue
            }
            var nexty = k1
            if(nexty + prevy > k2)
                nexty = k2 - prevy
            m += nexty
            prevy = nexty
        }
        println(m)
    }
}