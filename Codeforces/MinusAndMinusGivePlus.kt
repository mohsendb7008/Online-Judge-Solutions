fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val s1 = readLine()!!
        val s2 = readLine()!!
        val(n1, n2) = s1.length to s2.length
        var(ptr1, ptr2) = 0 to 0
        while(ptr1 < n1 && ptr2 < n2){
            if(s2[ptr2] == '-'){
                if(s1[ptr1] == '-'){
                    ptr1++
                    ptr2++
                }
                else
                    break
            }
            else{
                if(s1[ptr1] == '+'){
                    ptr1++
                    ptr2++
                }
                else if(ptr1 + 1 < n1 && s1[ptr1 + 1] == '-'){
                    ptr1 += 2
                    ptr2++
                }
                else
                    break
            }
        }
        println(if(ptr1 == n1 && ptr2 == n2) "YES" else "NO")
    }
}