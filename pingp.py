import os, logging, threading, time

def ipping (ip):
    #logging.info("Process {} starting".format(os.getpid()))
    logging.info("Thread {} starting".format(threading.current_thread().ident))
    time.sleep(3)
    os.system('nmap -sP {}'.format(ip))
    time.sleep(3)
    logging.info("Thread {} done".format(threading.current_thread().ident))
    #logging.info("Process {} done".format(os.getpid()))
    

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")
    ip = input('Write IP: ')
    logging.info("Process {} starting".format(os.getpid()))
    x = threading.Thread(target=ipping, args=(ip,))
    x.start()
    x.join()
    logging.info("Process {} done".format(os.getpid()))