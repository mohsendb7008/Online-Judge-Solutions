fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val s = readLine()!!
        var ans = 0
        var vs = 0
        for(c in s){
            if(c == 'w'){
                ans++
                if(vs > 0){
                    ans += vs / 2
                    vs = 0
                }
            }
            else
                vs++
        }
        if(vs > 0)
            ans += vs / 2
        println(ans)
    }
}