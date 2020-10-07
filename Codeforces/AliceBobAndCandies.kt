fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        val choc = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        var i = 0
        var j = n - 1
        var turn = true
        var ans = 0
        var c1 = 0
        var c2 = 0
        var prevy = 0
        var sum = 0
        while(i <= j){
            if(turn){
                c1 += choc[i]
                sum += choc[i]
                i++
            }else{
                c2 += choc[j]
                sum += choc[j]
                j--
            }
            if(sum > prevy){
                turn = !turn
                ans++
                prevy = sum
                sum = 0
            }
        }
        if(sum != 0)
            ans++
        println("$ans $c1 $c2")
    }
}