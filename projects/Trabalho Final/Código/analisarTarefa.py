import string

def contar_palavras(texto):
    palavras = texto.split()
    return len(palavras)

def identificar_palavras_chave(texto, comprimento_minimo=5):
    palavras = texto.split()
    palavras_chave = [palavra for palavra in palavras if len(palavra) >= comprimento_minimo]
    return palavras_chave
