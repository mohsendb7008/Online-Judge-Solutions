fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        val n = readLine()!!.toInt()
        when {
            n < 4 -> println("-1")
            n == 4 -> println("2 4 1 3")
            else -> {
                var cnt = 0
                var o = 1
                while(o <= n){
                    print("$o ")
                    o += 2
                    cnt++
                }
                o -= 5
                print("$o ")
                cnt++
                if(n % 2 == 1){
                    if(cnt < n){
                        o += 2
                        print("$o ")
                        cnt++
                    }
                    if(cnt < n){
                        o -= 4
                        print("$o ")
                        cnt++
                    }
                }
                else{
                    if(cnt < n){
                        o += 4
                        print("$o ")
                        cnt++
                    }
                    if(cnt < n){
                        o -= 2
                        print("$o ")
                        cnt++
                    }
                    if(cnt < n){
                        o -= 4
                        print("$o ")
                        cnt++
                    }
                }
                while(cnt < n){
                    o -= 2
                    print("$o ")
                    cnt++
                }
                println()
            }
        }
    }
}