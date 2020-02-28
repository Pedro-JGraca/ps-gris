package main

import (
	"fmt"
	"net"
)

func scaner(IP string,porta int) bool {
	address := fmt.Sprintf ("%s:%d", IP, porta)
	conn, err := net.Dial ("tcp", address)
	if err != nil {
//		fmt.Printf("Falha na conhexao com %s: %s\n" ,address, err.Error())
		return false
	}
	conn.Close()
	return true
}

func main() {

	var IP1 string
	var porta1 int
	var IP2 string
	var porta2 int
	var abriu1 bool
	var abriu2 bool

	fmt.Print("Diga primeiro IP: ")
	fmt.Scanln(&IP1)
	fmt.Print("Diga a porta do primeiro IP: ")
	fmt.Scanln(&porta1)
	fmt.Print("Diga segundo IP: ")
	fmt.Scanln(&IP2)
	fmt.Print("Diga a porta do segundo IP: ")
	fmt.Scanln(&porta2)


	abriu1 = scaner(IP1,porta1)
	abriu2 = scaner(IP2,porta2)

	if abriu1 == true {
		fmt.Printf("\nA primeira batida em: %s:%d retornou: OPEN\n",IP1,porta1)
	} else {
		fmt.Printf("\nA primeira batida em: %s:%d retornou: CLOSED\n",IP1,porta1)
	}

	if abriu2 == true {
		fmt.Printf("\nA Segunda batida em: %s:%d retornou: OPEN\n\n",IP2,porta2)
	} else {
		fmt.Printf("\nA Segunda batida em: %s:%d retornou: CLOSED\n\n",IP2,porta2)
	}
}
