<h1 align="center">
    M I N I T A L K
</h1>

___

## :memo: **About**

_The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus._.

### *Objectives*  
> + Unix logic

### *Skills*
> + Unix
> + Rigor

For detailed information, refer to the [**subject of this project**](https://github.com/CherdantsevIlya/minitalk/blob/master/content/en.subject.pdf).

___

## 🚀 **Description**

### Mandotary part

Minitalk is a communication program in the form of a client and server. Communication between the server and the client is done ONLY using UNIX signals (only two signals - SIGUSR1 and SIGUSR2).

The server must be launched first, and after being launched it must display its PID.

```c
 ./server
 pid: 4476 (e.g.)
```

The client will take as parameters:
+ The server PID.
+ The string that should be sent.

```
 ./client [pid] [message]
```

If no errors occured, then the server simply prints a message from the client.

Server should be able to receive strings from several clients in a row, without needing to be restarted. It is implemented using **sigaction** (as far as i remember).

### Bonus part

+ The server confirms every signal received by sending a signal to the client.
+ Support Unicode characters

___

## 🧮 **How it works?**

![GIF](https://github.com/CherdantsevIlya/minitalk/blob/master/content/minitalk.gif)
___

## 📌 **Useful links**

+ [Передача файла сигналами](https://habr.com/ru/post/122823/)
+ [Перехват сигналов: sigaction()](https://it.wikireading.ru/1055)
+ [Short introduction to signals in C](https://www.youtube.com/watch?v=5We_HtLlAbs&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=17) 
