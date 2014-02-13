package main

import (
    "net/http"
    "fmt"
    "io/ioutil"
)

func main() {
    fmt.Println("Hello world!")
    resp, err := http.Get("http://www.baidu.com")
    if err != nil {
	fmt.Println("error!")
    }
    defer resp.Body.Close()
    body, err := ioutil.ReadAll(resp.Body)
    str := string(body)
    fmt.Println(str + " " + string(len(body)));
}
