package main

import (
	"fmt"
	"net"
	"sync"
)

type MultiWorker struct {
	wg sync.WaitGroup
}


func (w *MultiWorker) Run(IP string, porta int, abriu bool) {

	fmt.Print("Diga o IP: ")
	fmt.Scanln(&IP)
	for i := 0;i<2;i++ {
		w.wg.Add(1)
		fmt.Print("Diga a porta do IP: ")
		fmt.Scanln(&porta)
		go scaner(w,IP,porta,&abriu)
	}
	w.wg.Wait()
}

func scaner(w *MultiWorker,IP string,porta int, abriu *bool) error {
	address := fmt.Sprintf ("%s:%d", IP, porta)
	conn, err := net.Dial ("tcp", address)
	defer w.wg.Done()
	if err != nil {
		*abriu = false
	} else {
		*abriu = true
		conn.Close()
	}
	if *abriu == true {
		fmt.Printf("\nA batida em: %s:%d retornou: OPEN\n",IP,porta)
	} else {
		fmt.Printf("\nA batida em: %s:%d retornou: CLOSED\n",IP,porta)
	}
	return err
}

func main() {
	w := &MultiWorker{}
	var IP string
	var porta int
	var abriu bool
	w.Run(IP, porta, abriu)

}
