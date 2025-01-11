FROM ubuntu:latest

RUN apt-get update \
    && apt-get install -y g++ \
    && apt-get install -y build-essential \
    && apt-get install -y python3

COPY . .
WORKDIR /

RUN make \
    && make ./PeriodicTableClient \
    && make ./QuadraticFormula

CMD [ "python3", "src/ExecutableScript.py" ]
