package main

import (
	"fmt"
	"net"
)

func scaner(IP string,porta int) error {
	address := fmt.Sprintf ("%s:%d"IP, porta)
	conn, err := net.Dial ("tcp", adress)
	if err != nil {
		fmt.Printf("Falha na conhexao com %s: %s\n" ,address, err.Error())
		return err
	}
	return nil
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




	if abriu1 == true {
		fmt.Printf("\nA primeira batida em: %s:%s retornou: OPEN\n",IP1,porta1)
	} else {
		fmt.Printf("\nA primeira batida em: %s:%s retornou: CLOSED\n",IP1,porta1)
	}

	if abriu2 == true {
		fmt.Printf("\nA Segunda batida em: %s:%s retornou: OPEN\n\n",IP2,porta2)
	} else {
		fmt.Printf("\nA Segunda batida em: %s:%s retornou: CLOSED\n\n",IP2,porta2)
	}
}
