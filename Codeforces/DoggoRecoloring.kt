fun main() {
    readLine()
    val s = readLine()!!.toCharArray().sorted()
    var ans = s.size == 1
    for(i in s.indices){
        if(i == s.lastIndex)
            break
        if(s[i] == s[i+1]){
            ans = true
            break
        }
    }
    println(if(ans) "Yes" else "No")
}