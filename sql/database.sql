-- 记账基本信息表

CREATE TABLE pocket (
    id          char(128)       NOT NULL,       -- id，时间 + 类别组成
    date        INT             NOT NULL,       -- 时间，精确到秒
    money       DOUBLE          NOT NULL,       -- 钱的数额
    money_type  INT             NOT NULL,       -- 支出/收入类别
    desc        TEXT            NOT NULL,       -- 说明
    PRIMARY KEY (`id`)
);
