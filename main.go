package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	// 703. Kth Largest Element in a Stream
	if len(os.Args) != 2 {
		panic("os.Args[1] must exist!")
	}

	lc := os.Args[1]

	lcNumber := strings.Split(lc, ".")[0]
	lcIndex := len(lcNumber)
	if lcIndex < 4 {
		lcNumber = strings.Repeat("0", 4-lcIndex) + lcNumber
	}

	directoryName := lcNumber + "-" + lc[lcIndex+2:]
	fmt.Println(directoryName)

	dir, err := os.Getwd()
	if err != nil {
		panic(err)
	}

	files, err := ioutil.ReadDir(dir)
	if err != nil {
		panic(err)
	}

	for _, file := range files {
		if directoryName == file.Name() {
			panic("leetCode already exist.")
		}
	}
	// 775
	err = os.Mkdir(directoryName, 0775)
	if err != nil {
		panic(err)
	}

	directoryName = directoryName + "/c++"
	err = os.Mkdir(directoryName, 0775)
	if err != nil {
		panic(err)
	}

	_, err = os.Create(directoryName + "/solution.cpp")
	if err != nil {
		panic(err)
	}
}
