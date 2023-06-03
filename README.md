# Projeto Segunda Unidade
    Projeto da segunda unidade da disciplina LP1 do BTI 2023

#### Aluno: Fagner Luan dos Santos Silva

### Como compilar e rodar
    Caso tenha baixado o projeto do github, será necessário excluir as pastas e os arquivos do cmake da pasta build bem como o aqruivo Makefile também na pasta build, para evitar problemas com o CMake.
    Na pasta do projeto entre na pasta build
    e digite o comando cmake ..
    Após isso, digite o comando make para compilar o programa. Para rodar, 
    digite o comando ./simple_song_player playlists.txt

## Observação
    Este roteiro contém apenas instruções para as funcionalidades a seguir: unir playlists, criar uma nova playlist com uma musica nova no fim - playlist + musica -, 
    diferença entre playlists, e criar uma nova playlist sem uma determinada musica -
    playlist - musica. Outras melhorias implementadas, as que modificam uma playlist, foram embutidas nas funcionalidades anteriores,
    como adicionar musicas(varias musicas através de outra playlist), remover musicas(varias musicas através de outra playlist), etc...
    Para essas funcionalidades o usuário fica livre para testar como quiser.
    As melhorias na classe Lista, foram implementadas porém não há um roteiro para testa-las, pois as melhorias na lista são refletidas na classe Playlist.

## Observação 2
    Em relação ao projeto anterior, Uma nova classe foi adicionada. A classe Driver é responsável por gerenciar as musicas do sistema e as playlists. Houveram modificações também na interface de interação em relação ao projeto anterior.


# Roteiro
    Quando o programa for rodado, as músicas e playlists no arquio playlists.txt
    serão adicionadas no sistema e na lista de playlists respectivamente.

### Unir playlists (Playlist + Playlist)
    Escolha a opção 12 no menu.
    Em seguida, escolha as playlists Mais tocadas e MPB.
    Quando solicitado escolha um nome para a nova playlist. Nome sugerido Nacionais.
    O usuário poderá ver a nova playlist disponivel e listar suas músicas, escolhendo as devidas opções no menu.

### Nova playlist com uma nova música no final (Playlist + Musica)
    No menu escolha a opção 13. Quando solicitado, escolha a playlist base para a nova playlist.
    Depois escolha uma musica do sistema que não esteja na playlist.
    Escolha um nome para a nova playlist.
    O usuário poderá ver a nova playlist disponivel e listar suas músicas, escolhendo as devidas opções no menu.

### Diferença entre playlists (Playlist - Playlist)
    Escolha a opção 14 no menu. Escolha a primeira e a segunda playlist envolvidas na operação.
    Playlists sugeridas Vibes e Indie.
    Quando solicitado dê um nome a nova playlist. Caso escolha as playlists sugeridas, um nome sugerigdo é Arctic Monkeys.
    O usuário poderá ver a nova playlist disponivel e listar suas músicas, escolhendo as devidas opções no menu.

### Criar uma nova playlist removendo uma música (Playlist - Musica)
    No menu escolha a opção 15. Escolha a playlist base para realizar a operação.
    Após isso, escolha uma das musicas disponivel na playlist escolhida.
    Dê um nome para a playlist criada.
    O usuário poderá ver a nova playlist disponivel e listar suas músicas, escolhendo as devidas opções no menu.
