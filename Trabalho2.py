def roundRobin(nomes, tempos, chegadas, prioridades):
    quantum = int(input("Insira o valor do quantum: "))

    tempoEspera = [0] * len(tempos)
    tempoResposta = [0] * len(tempos)
    tempoExec = [0] * len(tempos)
    tempoTotal = 0

    for i in range(len(tempos)):
        tempoEspera[i] = 0
        tempoResposta[i] = 0
        tempoExec[i] = 0
        tempoTotal += tempos[i]
    
    cont = 0
    qcont = 0
    procChegou = [False] * len(tempos)
    executando = 99
    executando0 = 0
    ttEsp = 0.0
    ttResp = 0.0

    lista = []

    print('\n[0]',nomes[0])

    while(cont <= tempoTotal):
        for j in range(len(tempos)):
            if(chegadas[j] == cont):
                lista.insert(j,j)
                procChegou[j] = True

        if(executando == 99 and len(lista) != 0):
            executando = lista.pop(0)

        for i in range(len(tempos)):
            if(procChegou[i] and tempoExec[i] < tempos[i]):
                if(i == executando):
                    tempoResposta[i] +=1
                else:
                    tempoResposta[i] +=1
                    tempoEspera[i] +=1
        
        if(cont < tempoTotal):  
            if(executando0 != executando):
                print(cont,nomes[executando])
                executando0 = executando
            else:
                print('-')
        tempoExec[executando]+=1
        qcont+=1

        if(qcont == quantum or tempoExec[executando] == tempos[executando]):
            if(tempoExec[executando] < tempos[executando]):
                lista.insert(qcont,executando)
            elif(qcont == len(tempos)):
                executando = 0
                qcont = 0
            else:
                executando = 99
                qcont = 0
        cont+=1

    print(f'[{tempoTotal}]')    

    print("Nome\t\t Tempo\t Chegada\tTempo de espera\tTempo de resposta\tPrioridade\n")
    for i in range(len(tempos)):
        print(f'{nomes[i]}\t\t{tempos[i]}\t{chegadas[i]}\t\t{tempoEspera[i]}\t\t{tempoResposta[i]}\t\t{prioridades[i]}')

    for i in range(len(tempos)):
        ttEsp = tempoEspera[i] + ttEsp

        ttResp = tempoResposta[i] + ttResp

    print("\nTempo médio de espera = ", round(ttEsp/len(tempos), 2))
    print("\nTempo médio de resposta = ", round(ttResp/len(tempos),2))
            



if __name__ == "__main__":

    arquivo = open('in.txt', 'r')

    linhas = arquivo.readlines()
    dados = {}

    for linha in linhas:
        valores = linha.strip().split()
        chave = valores[0]
        dados[chave] = valores[1:]

    arquivo.close()

    # Exemplo de acesso aos dados
    nomes = dados['Processo']
    tempos = dados['Tempo']
    chegadas = dados['Chegada']
    prioridades = dados['Prioridade']

    # Converter os vetores para inteiros
    tempos = [int(tempo) for tempo in tempos]
    chegadas = [int(chegada) for chegada in chegadas]
    prioridades = [int(prioridade) for prioridade in prioridades]

    roundRobin(nomes, tempos, chegadas, prioridades)
