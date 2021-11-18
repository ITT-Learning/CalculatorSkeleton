FROM node:12-alpine
WORKDIR /angularProject
RUN npm install -g @angular/cli

COPY package*.json ./
RUN npm install

RUN npm install bootstrap jquery tslib --save
RUN npm i
