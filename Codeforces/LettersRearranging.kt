fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val s = readLine()!!
        var same = true
        for(i in s.indices){
            if(s[i] != s[0]){
                same = false
                break
            }
        }
        if(same)
            println(-1)
        else
            println(s.toCharArray().sorted().joinToString(separator = ""))
    }
}