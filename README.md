Git은 분산 버전 관리 시스템 : 프로젝트에 참여하는 모든 클라이언트(개발자)가 전체 저장소에 대한 개별적인 로컬 저장소를 갖고 작업하는 형태
                            클라이언트는 각자가 온전한 전체 저장소의 사본을 로컬에 가지게 된다.
                            

# Git을 사용할 준비
- Git에서 커밋할 때마다 기록하는 사용자 이름과 메일 주소를 설정하는 명령입니다.
 - git --version
 - git config --global user.name "사용자 이름"
 - git config --global user.email "이메일
 
# 저장소에 사용에 필요한 Git 기본 명령어
 - git init : 실행한 위치를 Git 저장소로 초기화합니다. (저장소 생성)
 - git add 파일이름 : 해당 파일을 Git이 추적할 수 있게 저장소에 추가합니다.(저장소에 파일 추가)
 - git commit : 변경된 파일을 저장소에 제출합니다. (저장소에 수정 내역 제출)
 - git commit -a : 변경된 저장소 파일을 모두를 커밋하는 옵션 -a 
 - git commit -m "커밋 메세지"
 - git commit -am "커밋 메세지"
 - git status : 현재 저장소의 상태를 출력합니다. (저장소 상태 확인)
# 저장소 사용을 위한 branch 명령어
 - git branch 이름 : '이름'의 브랜치를 만듭니다.
 - git checkout -b 브랜치 이름 : git branch 명령과 git checkout 명령을 한 번에 실행하는 방법
 - git checkout 브랜치 이름 : 현재 작업 중인 "브랜치 이름"을 변경합니다.
 - git merge 브랜치 이름 : 현재 작업 중인 브랜치에 '브랜치 이름'의 브랜치를 끌어와 병합합니다.
  
 
 커밋 commit : 프로젝트에서 의미가 있는 최소한의 단위, '의미'를 가질 수 있게 되는 시기라면 언제든 커밋을 하는 것을 권장
   예) 일정 시간이 지난 경우, 매일매일 정해진 시간에 커밋한다는 규칙, 프로그래밍의 최소한 실행 단위인 함수단위, 그에 준하는 덩어들을 완성했을 때
 
 vim에서 사용되는 주요 명령어
- i : 입력 모드 전환(현재 위치부터 쓰기)
- o : 입력 모드 전환(다음 줄부터 쓰기)
- a : 입력 모드 전환(한 칸 뒤부터 쓰기)
- Esc : 일반 모드 전환(입력 또는 명령모드에서)
- (일반모드에서) : 명령 모드 전환
- w : 저장
- q : 종료

# git merge : master 브랜치와 병합
 - git checkout master
 - git merge "다른 브랜치"
 
# .gitignore : 불필요한 파일 및 폴더 무시

# git log : 기록보기 커밋 내역을 확인 할 수 있는 기능
 - git log -p : 각 커밋에 적용된 실제 변경 내용을 보여줍니다.
 - git log --word-diff : diff 명령의 실행 결과를 단어 단위로 보여줍니다.
 - git log --stat 각 커밋에서 수정된 파일을 통계 정보를 보여줍니다.
 - git log --name-only : 커밋 정보 중에서 수정된 파일의 목록만 보여줍니다.
 - git log --relative-date : 정확한 시간을 보여주는 것이 아니라 1일 전, 1주 전처럼 상대적인 시간을 비교하는 형식으로 보여줍니다.
 -(가장 자주 사용하는) git log --graph : 브랜치 분기와 병합 내역을 아스키 그래프로 보여줍니다.
 - git log --stat

# GitHub repository로 git push 할 때 에러 해결 법
- 에러 메세지 : Updates were rejected because the remote contains work that you do not have locally.
- 이유 : github에서 레포지토리를 생성할 때, README.md 파일을 생성했기 때문이다.
- 해결 : git pull 명렁어로 github의 원격 레포지토리를 내 로컬로 불러와서(fetch) 합친다(merge.)

# 깃(git) pull 명령 후 non-fast-forward 문제 해별방법
## 현상
  - github에서 저장소 생성 후 저장소 주소를 remote에 입력(git remote add origin https://github…..)했고, 로컬에서도 정상적으로 초기화(git init)했는데도 git pull 또는 git merge 명령이 동작하지 않고 git push origin master시 [rejected] master -> master (non-fast-forward)이런 에러가 발생하는 경우
## 원인
  - 깃허브에 생성된 원격 저장소와 로컬에 생성된 저장소 간 공통분모가 없는 상태에서 병합하려는 시도로 인해 발생. 기본적으로 관련 없는 두 저장소를 병합하는 것은 안되도록 설정되어 있음.

## 해결방법
  - git pull origin master --allow-unrelated-histories
  - 관련 없었던 두 저장소를 병합하도록 허용
 
