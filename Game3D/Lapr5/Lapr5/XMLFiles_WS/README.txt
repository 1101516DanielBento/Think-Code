Para gerar ficheiros do WS Utilizar a prompt do VS: 

svcutil /t:metadata http://wvm023.dei.isep.ipp.pt/GameWS/GameWebService.svc?wsdl
wsutil *.xsd *.wsdl


INSTRUCOES PROJECTO.
Propriedades do Projecto->configuration(All Confs)

c/c++->precompiled Headers: Precompiled Header->NOT USING PRECOMPILED HEADERS
linker->input: Aditional Dependencies->ADD(WebServices.lib)
